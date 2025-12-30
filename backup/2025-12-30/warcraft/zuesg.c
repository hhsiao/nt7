// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37;41m七劍[2;37;0m[2;37;0m", ({"zuesgs"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是葉七的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zuesg");
        set("owner_name", "葉七");
        set_temp("owner", "zuesg");
        set_temp("owner_name", "葉七");
        ::setup();
}
