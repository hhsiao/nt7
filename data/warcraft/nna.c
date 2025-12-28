// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是哈拉密碼的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nna");
        set("owner_name", "哈拉密碼");
        set_temp("owner", "nna");
        set_temp("owner_name", "哈拉密碼");
        ::setup();
}
