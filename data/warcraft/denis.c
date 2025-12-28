// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幸福健康[2;37;0m[2;37;0m", ({"happyy"}));        
        set("gender", "女性");                
        set("long", "你是我的吉祥物[2;37;0m
它是快樂的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "denis");
        set("owner_name", "快樂");
        set_temp("owner", "denis");
        set_temp("owner_name", "快樂");
        ::setup();
}
