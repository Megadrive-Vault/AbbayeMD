#include "../inc/include.h"


static GameObject *door;
static GameObject *fish   [ 3 ];
static GameObject *splash [ 3 ];
static GameObject *drop   [ 2 ];

static Item       *item;

static u8          nb_fish;
static u8          nb_splash;
static u8          nb_drop;

static u16         i;





static void _room_enter ( Room *room )
{
	door = (GameObject*) goManagerFindByEntityId ( &waObjects, 35, 0 );  // Door

	nb_fish   = goManagerFindAllByEntityId ( &waObjects, fish,   55 );   // Fish
	nb_splash = goManagerFindAllByEntityId ( &waObjects, splash, 56 );   // Splash
	nb_drop   = goManagerFindAllByEntityId ( &waObjects, drop,   54 );   // Toxic drop


	// the switch at 4,1 opens the door
	item = (Item*) itemManagerFind ( &waItems, 22, 4, 1 );

	if ( itemGetChecked ( item )  &&  itemGetVisible ( door->item ) )
	{
		// set a countdown to open
		itemSetValue ( door->item, getHz() );
	}


	for ( i = 0; i < nb_fish;   i++ ) { fish   [ i ]->grabity = false; fish   [ i ]->counter = 0; SPR_setVisible ( fish   [ i ]->sprite, 1 );  }
	for ( i = 0; i < nb_splash; i++ ) { splash [ i ]->grabity = false; splash [ i ]->counter = 0; SPR_setVisible ( splash [ i ]->sprite, 0 ); }
	for ( i = 0; i < nb_drop;   i++ ) { drop   [ i ]->grabity = false; drop   [ i ]->counter = 0; SPR_setVisible ( drop   [ i ]->sprite, 1 ); }

	philippe_init ( );
	philippe_add ( 10, 40);
	philippe_add ( 188, 210 );
}



static void _room_stay ( Room *room )
{
	if ( itemGetValue ( door->item ) > 0 )
	{
		itemIncValue ( door->item, -1 );
	}

	else if ( itemGetChecked ( item )  &&  itemGetVisible ( door->item ) )
	{
		hide_door ( door );
	}


	for ( i=0; i<nb_fish; i++ )
	{
		enemy_fish ( fish, splash, i );
	}

	for ( i=0; i<nb_drop; i++ )
	{
		enemy_drop ( drop, i );
	}

	philippe_update();
}





void room_funct_43_all ( Room *room, u8 action )
{
	if ( action == ROOM_ACTION_ENTER ) // enter
	{
		_room_enter ( room );
	}

	else if ( action == ROOM_ACTION_STAY ) // stay
	{
		_room_stay ( room );
	}

	else if ( action == ROOM_ACTION_LEAVE ) // leave
	{
		//_room_leave ( room );
	}
}
