// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("嗜血天嬌[2;37;0m[2;37;0m", ({"tjcw"}));        
        set("gender", "女性");                
        set("long", "嗜血天嬌[2;37;0m
它是獨孤天驕的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dgtj");
        set("owner_name", "獨孤天驕");
        set_temp("owner", "dgtj");
        set_temp("owner_name", "獨孤天驕");
        ::setup();
}
