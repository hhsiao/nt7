// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m毛頭[2;37;0m[2;37;0m", ({"zhg"}));        
        set("gender", "女性");                
        set("long", "長的很醜[2;37;0m
它是買菜大嬸的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kamuls");
        set("owner_name", "買菜大嬸");
        set_temp("owner", "kamuls");
        set_temp("owner_name", "買菜大嬸");
        ::setup();
}
