// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小蕾[2;37;0m[2;37;0m", ({"xiaolei"}));        
        set("gender", "女性");                
        set("long", "我的[2;37;0m
它是小妾的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaoqie");
        set("owner_name", "小妾");
        set_temp("owner", "xiaoqie");
        set_temp("owner_name", "小妾");
        ::setup();
}
