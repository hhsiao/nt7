// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "$HIM$朱雀[2;37;0m
它是尋歡的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xunhuan");
        set("owner_name", "尋歡");
        set_temp("owner", "xunhuan");
        set_temp("owner_name", "尋歡");
        ::setup();
}
