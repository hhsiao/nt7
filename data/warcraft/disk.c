// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m血鶯[2;37;0m[2;37;0m", ({"bloodeve"}));        
        set("gender", "女性");                
        set("long", "血色老鶯[2;37;0m
它是盤子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "disk");
        set("owner_name", "盤子");
        set_temp("owner", "disk");
        set_temp("owner_name", "盤子");
        ::setup();
}
