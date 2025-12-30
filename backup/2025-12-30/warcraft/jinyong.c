// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m天書[2;37;0m[2;37;0m", ({"skybook"}));        
        set("gender", "女性");                
        set("long", "哈哈[2;37;0m
它是查良鏞的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jinyong");
        set("owner_name", "查良鏞");
        set_temp("owner", "jinyong");
        set_temp("owner_name", "查良鏞");
        ::setup();
}
