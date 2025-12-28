// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m藍鳳[2;37;0m[2;37;0m", ({"myshou"}));        
        set("gender", "女性");                
        set("long", "四大神獸[2;37;0m
它是藍色妖姬的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kingoy");
        set("owner_name", "藍色妖姬");
        set_temp("owner", "kingoy");
        set_temp("owner_name", "藍色妖姬");
        ::setup();
}
