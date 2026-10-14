from pathlib import Path
import re, subprocess, os
root=Path(__file__).resolve().parents[2]
source=(root/'src/client/component/stringtable_override.cpp').read_text(encoding='utf-8-sig')
def function(name):
 match=re.search(r'\b(?:int|bool|csv_parse_result|std::string|build_result)\s+'+name+r'\([^;]*?\)\s*\{', source)
 if not match: raise RuntimeError('Missing production helper: '+name)
 start=source.index('{',match.start()); depth=0; quote=None; escaped=False; comment=None; i=start
 while i<len(source):
  c=source[i];n=source[i+1:i+2]
  if comment=='line':
   if c=='\n':comment=None
  elif comment=='block':
   if c=='*' and n=='/':comment=None;i+=1
  elif quote:
   if escaped:escaped=False
   elif c=='\\':escaped=True
   elif c==quote:quote=None
  elif c=='/' and n=='/':comment='line';i+=1
  elif c=='/' and n=='*':comment='block';i+=1
  elif c in ('"',"'"):quote=c
  elif c=='{':depth+=1
  elif c=='}':
   depth-=1
   if depth==0:return source[match.start():i+1]
  i+=1
 raise RuntimeError('Unclosed function')
constants='\n'.join(re.findall(r'constexpr std::size_t (?:max_file_size|max_rows|max_columns|max_table_cells)\s*=.*?;',source))
helpers='\n'.join(function(n) for n in ['cell_hash','is_safe_asset_name','parse_csv','override_cache_key','build_table'])
cpp=r'''#include <algorithm>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
namespace utils::string { std::string to_lower(std::string s) { std::transform(s.begin(),s.end(),s.begin(),[](unsigned char c){return static_cast<char>(std::tolower(c));});return s;} }
struct csv_data {std::vector<std::vector<std::string>> rows{};std::size_t columns{};};
enum class csv_parse_result {ok,too_many_cells,unterminated_quote};
namespace game { struct StringTableCell {const char* string;int hash;};struct StringTable {const char* name;int rowCount;int columnCount;StringTableCell* values;}; }
constexpr char empty_cell[]="";
enum class build_result {ok,empty,too_many_cells,allocation_failed};
struct table_storage {int allocations=0;void reserve(std::size_t){};void release(){};template<class T>T* allocate_array(std::size_t){++allocations;return nullptr;}char* duplicate_string(const std::string&){++allocations;return nullptr;}};
'''+constants+'\n'+helpers+r'''
void require(bool ok,const char* why){if(!ok){std::cerr<<why<<"\n";std::exit(1);}}
int main(){
 csv_data table;
 require(parse_csv("a,\"b,c\"\n",table)==csv_parse_result::ok,"quoted CSV parse");
 require(table.rows.size()==1 && table.columns==2 && table.rows[0][1]=="b,c","quoted cell retained");
 table={};require(parse_csv("\"unterminated",table)==csv_parse_result::unterminated_quote,"reject unmatched quote");
 table={};require(parse_csv("a,b\n\n",table)==csv_parse_result::ok && table.rows.size()==2,"blank line indices");
 table={};std::string ragged(999,',');ragged+='\n';ragged+=std::string(1100,'\n');
 require(parse_csv(ragged,table)==csv_parse_result::ok,"ragged CSV parse");
 table_storage storage;game::StringTable* output=nullptr;
 require(build_table("mp/test.csv",table,storage,output)==build_result::too_many_cells && output==nullptr && storage.allocations==0,"reject padded table before allocation");
 require(cell_hash("AbC")==96354 && cell_hash("ABC")==cell_hash("abc"),"engine-compatible case-fold hash");
 require(is_safe_asset_name("mp/example.csv") && !is_safe_asset_name("../outside.csv") && !is_safe_asset_name("C:/outside.csv"),"asset path guards");
 const auto first=override_cache_key("MP/example.csv","D:/mods/first/mp/example.csv");
 const auto second=override_cache_key("mp/example.csv","D:/mods/second/mp/example.csv");
 require(first!=second,"mod switch must not reuse another path's table");
 require(first==override_cache_key("mp/EXAMPLE.csv","d:/MODS/FIRST/mp/EXAMPLE.csv"),"Windows case-insensitive cache identity");
 require(override_cache_key("mp/example.csv","")!=first,"previous miss must not mask mounted CSV");
 std::cout<<"PASS production CSV parser, quoting, padded-cell budget, asset guards, engine hash and mod-path cache keys\n";
}
'''
build=root/'build/tests/stringtables';build.mkdir(parents=True,exist_ok=True)
cpp_path=build/'production-parser.cpp';exe=build/'production-parser.exe';cpp_path.write_text(cpp,encoding='utf-8')
subprocess.run(['cl','/nologo','/std:c++20','/EHsc',str(cpp_path),'/Fe:'+str(exe),'/Fo:'+str(build/'production-parser.obj')],check=True)
subprocess.run([str(exe)],check=True)