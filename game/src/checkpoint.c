#include "../inc/include.h"



static Checkpoint  _checkpoint;



static void _set_object ( GameObject *check )
{
	check->object = (Object*) &checkpoint_list [ game.version ] [ 1 ];
	SPR_setAnim ( check->sprite, check->object->entity->animation );
}



void checkpoint_init ( )
{
	_checkpoint = (Checkpoint) { 120, 156, 0, 1 };

	if ( game.crusader )
	{
		_checkpoint.room_x = 1;
	}
}



void checkpoint_save ( GameObject *check )
{
	_checkpoint = (Checkpoint) { check->x, check->y, game.room.x, game.room.y };

	play_fx ( FX_SWITCH );

	_set_object ( check );
	updateSprites ( ); // SPR_update ( (Sprite*) &waSprites, wvSpriteCounter );

	goUpdate ( player.go );
	PlayerAction action = playerGetAction ( &player );
	playerUpdate ( &player, action );

	VDP_waitVSync ( );

	waitHz ( getHz ( ) );
}



void checkpoint_draw ( GameObject *check )
{
	if ( game.room.x == _checkpoint.room_x  &&  game.room.y == _checkpoint.room_y )
	{
		_set_object ( check );
	}
}



Checkpoint *checkpoint_get ( )
{
	return (Checkpoint*) &_checkpoint;
}