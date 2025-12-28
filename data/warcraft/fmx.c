// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m皮娃娃[5m[1;37m霍啟剛[2;37;0m[2;37;0m", ({"car"}));        
        set("gender", "男性");                
        set("long", "這是淘寶熱銷的霍啟剛版皮娃娃，襠下有神器，引眾多少女競脫褲。[2;37;0m
它是伏明霞的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "fmx");
        set("owner_name", "伏明霞");
        set_temp("owner", "fmx");
        set_temp("owner_name", "伏明霞");
        ::setup();
}
