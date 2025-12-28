// Room: xiangfang.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "廂房");
        set("long", @LONG
這是內室廂房，四周佈置一望便知是小姐的閨房。石桌石凳，頗有山野氣
息，房裡亂掛了些書畫，一望可知主人是沒有什麼修養的。窗外盛開著一些野
山茶花，不遠處的山石提醒你這是在一個山谷裡。
LONG
        );
        set("exits", ([            
            "west" : __DIR__"keting",
        ]));

        set("objects", ([
              __DIR__"npc/gan_baobao" : 1,
        ]));
        
        setup();
}