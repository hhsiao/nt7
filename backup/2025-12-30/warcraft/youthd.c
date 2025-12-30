// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m不[1;35m帥[1;36m臉上[1;31m踹[2;37;0m[2;37;0m[2;37;0m", ({"guys"}));        
        set("gender", "男性");                
        set("long", "不帥臉上踹[2;37;0m
它是騷年的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "youthd");
        set("owner_name", "騷年");
        set_temp("owner", "youthd");
        set_temp("owner_name", "騷年");
        ::setup();
}
