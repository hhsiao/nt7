// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m鳥叔[2;37;0m[2;37;0m", ({"niaoshu"}));        
        set("gender", "女性");                
        set("long", "$HIB$鳥叔[2;37;0m
它是寧一的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ninga");
        set("owner_name", "寧一");
        set_temp("owner", "ninga");
        set_temp("owner_name", "寧一");
        ::setup();
}
