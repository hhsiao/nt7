// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m飛鳥一現[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "飛呀飛呀[2;37;0m
它是胡一飛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mavis");
        set("owner_name", "胡一飛");
        set_temp("owner", "mavis");
        set_temp("owner_name", "胡一飛");
        ::setup();
}
