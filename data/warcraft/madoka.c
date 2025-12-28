// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m月野兔[2;37;0m[2;37;0m", ({"yyt"}));        
        set("gender", "女性");                
        set("long", "可愛的美少女[2;37;0m
它是鹿目圓香的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "madoka");
        set("owner_name", "鹿目圓香");
        set_temp("owner", "madoka");
        set_temp("owner_name", "鹿目圓香");
        ::setup();
}
