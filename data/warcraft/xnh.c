// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "這是一輛公主自行車[2;37;0m
它是小女孩的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xnh");
        set("owner_name", "小女孩");
        set_temp("owner", "xnh");
        set_temp("owner_name", "小女孩");
        ::setup();
}
