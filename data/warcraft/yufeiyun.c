// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m碧水[2;37;0m[2;37;0m", ({"qiling"}));        
        set("gender", "男性");                
        set("long", "飛天遁地[2;37;0m
它是楓葉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yufeiyun");
        set("owner_name", "楓葉");
        set_temp("owner", "yufeiyun");
        set_temp("owner_name", "楓葉");
        ::setup();
}
