// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m好聲音轉椅[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這個是從英國空運來的豪華轉椅，由犀牛皮做成，價值80多萬。[2;37;0m
它是那英的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "naying");
        set("owner_name", "那英");
        set_temp("owner", "naying");
        set_temp("owner_name", "那英");
        ::setup();
}
