// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m小飛[2;37;0m[2;37;0m", ({"xiaofei"}));        
        set("gender", "女性");                
        set("long", "朱雀[2;37;0m
它是菜鳥飛飛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fei");
        set("owner_name", "菜鳥飛飛");
        set_temp("owner", "fei");
        set_temp("owner_name", "菜鳥飛飛");
        ::setup();
}
