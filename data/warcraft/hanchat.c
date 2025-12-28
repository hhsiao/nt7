// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m白鳶[2;37;0m[2;37;0m", ({"baiyuan"}));        
        set("gender", "女性");                
        set("long", "美麗[2;37;0m
它是韓小戳的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hanchat");
        set("owner_name", "韓小戳");
        set_temp("owner", "hanchat");
        set_temp("owner_name", "韓小戳");
        ::setup();
}
