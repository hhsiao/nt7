// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[31m飛天神獸[35m麒麟[2;37;0m[2;37;0m", ({"qilun"}));        
        set("gender", "男性");                
        set("long", "天空中突然一道閃電，一瞬間，一隻神物出現在你的面前...[2;37;0m
它是亂來的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "testa");
        set("owner_name", "亂來");
        set_temp("owner", "testa");
        set_temp("owner_name", "亂來");
        ::setup();
}
