// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m移動睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "只要躺在它背上就可以美美的睡上一覺。[2;37;0m
它是風清揚的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "keenjang");
        set("owner_name", "風清揚");
        set_temp("owner", "keenjang");
        set_temp("owner_name", "風清揚");
        ::setup();
}
