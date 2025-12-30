// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "神獸啊[2;37;0m
它是阿濤的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "djt");
        set("owner_name", "阿濤");
        set_temp("owner", "djt");
        set_temp("owner_name", "阿濤");
        ::setup();
}
