// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("北[2;37;0m[2;37;0m", ({"bei"}));        
        set("gender", "女性");                
        set("long", "方[2;37;0m
它是嵐天的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "flywind");
        set("owner_name", "嵐天");
        set_temp("owner", "flywind");
        set_temp("owner_name", "嵐天");
        ::setup();
}
