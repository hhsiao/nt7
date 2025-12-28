// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m九[1;36m頭[1;34m鳥[2;37;0m[2;37;0m", ({"winds"}));        
        set("gender", "男性");                
        set("long", "$HIW$九$HIC$頭$HIB$鳥[2;37;0m
它是疾風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ajax");
        set("owner_name", "疾風");
        set_temp("owner", "ajax");
        set_temp("owner_name", "疾風");
        ::setup();
}
