// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m真愛二龍[2;37;0m[2;37;0m", ({"lilongb"}));        
        set("gender", "女性");                
        set("long", "天下有情人終成眷屬[2;37;0m
它是李二娟的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lijuanb");
        set("owner_name", "李二娟");
        set_temp("owner", "lijuanb");
        set_temp("owner_name", "李二娟");
        ::setup();
}
