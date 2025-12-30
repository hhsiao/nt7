// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m不[1;35m帥[1;36m臉上[1;31m踹[2;37;0m[2;37;0m[2;37;0m", ({"guys"}));        
        set("gender", "男性");                
        set("long", "不帥臉上踹[2;37;0m
它是騷年的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "youthh");
        set("owner_name", "騷年");
        set_temp("owner", "youthh");
        set_temp("owner_name", "騷年");
        ::setup();
}
