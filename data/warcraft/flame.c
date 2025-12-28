// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m始熊貓[2;37;0m[2;37;0m", ({"panda"}));        
        set("gender", "女性");                
        set("long", "熊貓始祖，福澤蒼生！[2;37;0m
它是炎焱的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "flame");
        set("owner_name", "炎焱");
        set_temp("owner", "flame");
        set_temp("owner_name", "炎焱");
        ::setup();
}
