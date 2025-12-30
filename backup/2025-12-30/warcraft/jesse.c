// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("天之虎[2;37;0m[2;37;0m", ({"skyt"}));        
        set("gender", "女性");                
        set("long", "蒼天之神獸，全身發出白色的神光···[2;37;0m
它是風小飛的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jesse");
        set("owner_name", "風小飛");
        set_temp("owner", "jesse");
        set_temp("owner_name", "風小飛");
        ::setup();
}
