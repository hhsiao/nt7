// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小奇[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "兇猛[2;37;0m
它是獨孤求錢的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hmj");
        set("owner_name", "獨孤求錢");
        set_temp("owner", "hmj");
        set_temp("owner_name", "獨孤求錢");
        ::setup();
}
