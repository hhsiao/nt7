// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m嶽靈珊[2;37;0m[2;37;0m", ({"yls"}));        
        set("gender", "女性");                
        set("long", "美女[2;37;0m
它是往事無的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lbinca");
        set("owner_name", "往事無");
        set_temp("owner", "lbinca");
        set_temp("owner_name", "往事無");
        ::setup();
}
