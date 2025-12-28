// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("獸獸[2;37;0m[2;37;0m", ({"qiling"}));        
        set("gender", "男性");                
        set("long", "獸獸[2;37;0m
它是測試甲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "abctest");
        set("owner_name", "測試甲");
        set_temp("owner", "abctest");
        set_temp("owner_name", "測試甲");
        ::setup();
}
