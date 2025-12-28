// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m赤[37m魔[1;32m龍[2;37;0m[2;37;0m", ({"chimolong"}));        
        set("gender", "男性");                
        set("long", "不滅真身[2;37;0m
它是齊天大魔的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "qitdamo");
        set("owner_name", "齊天大魔");
        set_temp("owner", "qitdamo");
        set_temp("owner_name", "齊天大魔");
        ::setup();
}
