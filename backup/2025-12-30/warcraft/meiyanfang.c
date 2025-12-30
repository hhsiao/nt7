// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m烈焰紅唇[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "女性");                
        set("long", "我愛我的龍龍[2;37;0m
它是梅豔芳的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "meiyanfang");
        set("owner_name", "梅豔芳");
        set_temp("owner", "meiyanfang");
        set_temp("owner_name", "梅豔芳");
        ::setup();
}
