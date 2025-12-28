// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;35m小澤瑪利亞[2;37;0m[2;37;0m", ({"xoxo"}));        
        set("gender", "女性");                
        set("long", "小澤瑪利亞同時有著西方女優的狂野性感和東方女性的溫柔唯美。[2;37;0m
它是耶穌的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yes");
        set("owner_name", "耶穌");
        set_temp("owner", "yes");
        set_temp("owner_name", "耶穌");
        ::setup();
}
