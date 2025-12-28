// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m正氣[2;37;0m[2;37;0m[2;37;0m", ({"zqj"}));        
        set("gender", "女性");                
        set("long", "正氣麒麟[2;37;0m
它是正氣訣的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zhengqi");
        set("owner_name", "正氣訣");
        set_temp("owner", "zhengqi");
        set_temp("owner_name", "正氣訣");
        ::setup();
}
