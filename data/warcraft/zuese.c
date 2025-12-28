// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31;47m空中客車[2;37;0m[2;37;0m", ({"zueses"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是口十的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zuese");
        set("owner_name", "口十");
        set_temp("owner", "zuese");
        set_temp("owner_name", "口十");
        ::setup();
}
