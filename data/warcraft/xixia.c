// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("毅飛翔[2;37;0m[2;37;0m", ({"xixiaaa"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是洗毅的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xixia");
        set("owner_name", "洗毅");
        set_temp("owner", "xixia");
        set_temp("owner_name", "洗毅");
        ::setup();
}
