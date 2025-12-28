// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("靈芝瑞獸麒麟[2;37;0m[2;37;0m", ({"huashanxmride"}));        
        set("gender", "女性");                
        set("long", "靈芝瑞獸麒麟[2;37;0m
它是嶽靈芝的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "huashanxm");
        set("owner_name", "嶽靈芝");
        set_temp("owner", "huashanxm");
        set_temp("owner_name", "嶽靈芝");
        ::setup();
}
