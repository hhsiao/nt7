
inherit DEMONROOM;

void create()
{ 
        set("short", "山道"); 
        set("long", 
"這裡已經快到雁門關了，滿眼望去，盡是曲曲折折的山道，大軍行到 
此處，人畜都開始有些吃力起來。\n" 
); 
        set("outdoors", "yanmen"); 
        set("no_fly",1); 
        set("exits", ([ 
                "south"  : __DIR__"luanshi1", 
        ])); 
        set("n_time", 30); 
        set("n_npc", 5); 
        set("n_max_npc", 15);
        set("s_npc", __DIR__"npc/qidanbing");

        setup();
}
