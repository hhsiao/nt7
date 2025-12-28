// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m天使之翼[2;37;0m[2;37;0m", ({"redflg"}));        
        set("gender", "男性");                
        set("long", "一隻青色的龍。[2;37;0m
它是歐陽星雲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cwz");
        set("owner_name", "歐陽星雲");
        set_temp("owner", "cwz");
        set_temp("owner_name", "歐陽星雲");
        ::setup();
}
