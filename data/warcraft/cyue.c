// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m海上生明月[2;37;0m[2;37;0m", ({"seamoon"}));        
        set("gender", "女性");                
        set("long", "天涯共此時[2;37;0m
它是滄月的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cyue");
        set("owner_name", "滄月");
        set_temp("owner", "cyue");
        set_temp("owner_name", "滄月");
        ::setup();
}
