// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("霓裳[2;37;0m[2;37;0m", ({"mmxx"}));        
        set("gender", "女性");                
        set("long", "一隻朱雀[2;37;0m
它是慕容無瑕的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sklar");
        set("owner_name", "慕容無瑕");
        set_temp("owner", "sklar");
        set_temp("owner_name", "慕容無瑕");
        ::setup();
}
