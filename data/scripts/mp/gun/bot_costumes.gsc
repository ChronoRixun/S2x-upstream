// Gun Game's weapon change (maps/mp/gametypes/gun::_id_479C) rebuilds every
// player's costume from their saved profile outfits, then notifies
// "applyLoadout". Bots have no saved outfits, so they lose their bodies. The
// class script gives bots a generated costume (_func_333) instead; put that
// back after each loadout. The stock function can't be changed without
// replacing the whole gametype script.
main()
{
	// Stock Gun Game leaves costumes alone on Sandbox.
	if ( getdvar( "mapname" ) == "mp_sandbox_01" )
		return;

	level thread on_player_connect();
}

on_player_connect()
{
	for ( ;; )
	{
		level waittill( "connected", player );

		if ( isbot( player ) )
			player thread restore_costume();
	}
}

restore_costume()
{
	self endon( "disconnect" );
	self.s2x_costumes = [];

	for ( ;; )
	{
		self waittill( "applyLoadout" );

		// _id_5097 is the customization override that _id_0510::_id_73CA respects.
		if ( isdefined( self._id_5097 ) && self._id_5097 )
			continue;

		// _id_0079 is the division. Gun Game dresses everyone as Allies and,
		// like the class script, division 5 uses division 0's costume.
		division = 0;
		if ( isdefined( self._id_0079 ) && self._id_0079 != 5 )
			division = self._id_0079;

		// The class script generates a bot's costume once and keeps it.
		if ( !isdefined( self.s2x_costumes[division] ) )
			self.s2x_costumes[division] = _func_333( division, 1 );

		// _id_267E is the costume; apply it the way _id_0510::_id_73CA does.
		self._id_267E = self.s2x_costumes[division];
		self _meth_84C7( self._id_267E, undefined, 1, 1 );
		self loadcustomizationplayerview( self );
	}
}
