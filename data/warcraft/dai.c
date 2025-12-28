// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"vermilion"}));        
        set("gender", "女性");                
        set("long", "上古四大神獸之一。她是一種紅色的鳥，其身覆蓋火焰，終日不滅。[2;37;0m
它是小呆的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dai");
        set("owner_name", "小呆");
        set_temp("owner", "dai");
        set_temp("owner_name", "小呆");
        ::setup();
}
