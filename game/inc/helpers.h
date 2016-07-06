#ifndef _HELPERS_H_
#define _HELPERS_H_






//#define IS      ==
//#define AND     &&
//#define OR      ||
//#define NOT     !



#define BUTTON_ABC   ( BUTTON_A | BUTTON_B | BUTTON_C )
#define BUTTON_ABCS  ( BUTTON_ABC | BUTTON_START )



#define zero FIX32(0)





#define listptr_find( list, type, field, search ) \
({                                                \
	listptrNode *node = list->head;                \
	type *o = NULL;                                \
                                                  \
	while ( node )                                 \
	{                                              \
		o = (type*) node->pointer;                  \
                                                  \
		if ( o->field == search )                   \
		{                                           \
			break;                                   \
		}                                           \
                                                  \
		node = node->next;                          \
	}                                              \
	                                               \
	o;                                             \
})



#define SPR_getWidth(s)  ( (s)->frame[0].w )
#define SPR_getHeight(s) ( (s)->frame[0].h )

#define SPR_getVFlip(s)  ( ( (s)->attribut >> 12 ) & 1 )
#define SPR_getHFlip(s)  ( ( (s)->attribut >> 11 ) & 1 )





typedef struct
{
	fix32 x;
	fix32 y;
}
Vect2D_f32;


void  my_SPR_setFrame            ( Sprite *sprite, s16 frame );
void  SPR_setVFlip               ( Sprite *sprite, u8 VFlip );
void  SPR_setHFlip               ( Sprite *sprite, u8 HFlip );
u16   SPR_nbTiles                ( Sprite *sprite );
s16   SPR_getXPosition           ( Sprite *sprite );
s16   SPR_getYPosition           ( Sprite *sprite );
void  SPR_setTimer               ( Sprite *sprite, u16 timer );
void  SPR_setVisible             ( Sprite *sprite, u16 visible );
void  SPR_setAll                 ( Sprite *sprite, s16 visible, s16 frame, s16 timer );
u16   SPR_getNextFrame           ( Sprite *sprite );


//u8   SPR_getWidth               ( Sprite *sprite );
//u8   SPR_getHeight              ( Sprite *sprite );
//u8   SPR_getVFlip               ( Sprite *sprite );
//u8   SPR_getHFlip               ( Sprite *sprite );

u8   *my_strtok                  ( u8 *string, u8 delimitador );
u32   my_strtol                  ( u8 *cadena );
void  my_strpad                  ( u8 *str, const u8 size, u8 type );
u16   my_strcmp                  ( u8 *str1, u8 *str2 );
void  drawText                   ( const char *str, u16 x, u16 y );
void  drawInt                    ( u32 number, u8 x, u8 y, u8 leading_zeros );
void  drawUInt                   ( u32 number, u8 x, u8 y, u8 leading_zeros );
void  drawUIntBG                 ( u32 number, u8 x, u8 y, u8 leading_zeros, u16 plan, u16 flags );
u16   drawImage                  ( Image *image, u16 plan );
u16   drawImageXY                ( Image *image, u16 plan, u16 x, u16 y );
void  drawMem                    ( u8 x, u8 y );
u32   ntsc2pal                   ( u32 value );
u8    getHz                      ( );
void  waitHz                     ( u16 hzs );
void  waitSc                     ( u16 sc );
void  waitJoy                    ( );
void  waitJoySc                  ( u16 sc );
u16   between                    ( s32 min, s32 nb, s32 max );
void  resetPalettes              ( );
void  resetVRAM                  ( );
void  resetScroll                ( );
void  resetSprites               ( );
void  resetScreen                ( );
void  fadeIn                     ( u16 pal0[16], u16 pal1[16], u16 pal2[16], u16 pal3[16], u16 numframe, u8 async );

void  VDP_setSpriteAttributes    ( u16 index, u16 tile_attr );
void  VDP_setSpriteVRAM          ( u16 index, u16 pos );
void  VDP_setSpritePiority       ( u16 index, u16 high );
u16   VDP_getTile                ( u16 plan, u16 x, u16 y );
void  VDP_setTilePriority        ( u16 plan, u16 value, u16 x, u16 y );
void  VDP_setTileVRAM            ( u16 plan, u16 index, u16 x, u16 y );
s16   VDP_getHorizontalScroll    ( VDPPlan plan );
s16   VDP_getVerticalScroll      ( VDPPlan plan );

u16   in_array                   ( u16 needle, u16 array[] );

void  play_fx                    ( u8 fx );
void  play_music                 ( u8 track );

u16   goIsItem                   ( GameObject *go );
u16   goGetEntityType            ( GameObject *go );

s16   set_value_in               ( s16 value, s16 value_min, s16 value_max );

void  hide_door                  ( GameObject *door );
void  setDoor                    ( GameObject *door, bool value );

void  invert_cross               ( GameObject *cross );
void  setActive                  ( GameObject *go, u8 active );
void  update_palette_pressed     ( );
void  update_palette             ( );
void  show_screen                ( u16 wait );
//u16   find_values                ( u16 needle, u16 value, ... );

void  pack_vram_init             ( );
void  pack_vram_add              ( GameObject *go );

void swap_tiles                  ( Vect2D_u16 exception[], u8 count, u16 x1, u16 y1, u16 x2, u16 y2 );

void alternate_color_in_cm       ( );
void updateSprites               ( );

#endif
