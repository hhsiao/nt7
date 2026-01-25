# NT7 MUD Development Guide

## Project Overview
NT7 (泥潭7) is a traditional Chinese martial arts MUD (Multi-User Dungeon) game server written in LPC (Lars Pensjö C), running on FluffOS v2025.1205.0. This is a Traditional Chinese (繁體中文) fork of the original Simplified Chinese codebase.

## Architecture

### Core Components
- **Driver**: FluffOS engine (`../fluffos/build/bin/driver`) executes LPC code
- **Master Object** (`/adm/kernel/master.c`): Core interface between driver and mudlib
- **Simulated EFUNs** (`/adm/kernel/simul_efun.c`): Extended built-in functions
- **Daemons** (`/adm/daemons/`): Singleton services (e.g., `logind.c`, `combatd.c`, `skillsd.c`)
- **Virtual Object System** (`/adm/daemons/virtuald.c`): Dynamic object generation via `compile_object()`

### Directory Structure
- `/adm/`: Administrative code (kernel, daemons, system files)
- `/cmds/`: Player commands (`/std/`, `/usr/`, `/wiz/`, `/arch/`)
- `/clone/`: Object blueprints (weapons, armor, NPCs, items)
- `/d/`: Game world rooms organized by regions (e.g., `/d/beijing/`, `/d/shaolin/`)
- `/inherit/`: Base classes for objects (`/char/`, `/item/`, `/room/`, `/skill/`)
- `/include/`: Header files with constants and macros
- `/kungfu/`: Martial arts skill system
- `/data/`: Persistent data storage
- `/u/`: User/wizard directories

### Object Inheritance Pattern
Objects use multiple inheritance with feature modules:
```lpc
inherit F_DBASE;      // Data storage capabilities
inherit F_CLEAN_UP;   // Automatic cleanup
inherit F_MOVE;       // Movement functionality
inherit F_NAME;       // Naming system
```
Common patterns: characters inherit from `/inherit/char/char.c`, items from `/inherit/item/item.c`, rooms from `/inherit/room/room.c`.

## Conventions

### Naming Standards
- **Daemons**: Suffix with `d.c` (e.g., `logind.c`, `combatd.c`)
- **Global daemon references**: Use `_D` suffix macros defined in `/include/globals.h`:
  ```lpc
  #define LOGIN_D    "/adm/daemons/logind"
  #define COMBAT_D   "/adm/daemons/combatd"
  ```
- **Files**: Use lowercase with underscores (e.g., `simul_efun.c`, `mine_field.c`)
- **Include guards**: `#ifndef __NAME__` / `#define __NAME__` / `#endif`

### Daemon Communication
Access daemons through macro shortcuts:
```lpc
CHANNEL_D->do_channel(this_object(), "sys", "System message");
LOGIN_D->enter_world(ob, user);
COMBAT_D->fight(me, target);
```

### Data Management
- **DBASE system**: Use `set()`, `query()`, `add()`, `delete()` for object properties
- **Save/restore**: Objects inherit `F_SAVE` to persist data via `save()` and `restore()`
- **Database**: PostgreSQL integration via `/adm/etc/database.h` for user accounts

### Color and ANSI
Use ANSI codes from `/include/ansi.h`:
```lpc
#include <ansi.h>
write(HIR "紅色文字" NOR);  // High intensity red
write(HIC "青色文字" NOR);  // High intensity cyan
```

### Language
- All user-facing text is Traditional Chinese (繁體中文)
- Comments can be English or Chinese
- String encoding: GBK on port 5555, UTF-8 on port 6666

## Development Workflow

### Running the Server
```bash
# Start with auto-restart script
./start.sh

# Direct start
../fluffos/build/bin/driver config.ini
```

### Ports
- 5555: Telnet (GBK encoding)
- 6666: Telnet (UTF-8 encoding)
- 8888: WebSocket/HTTP (web client via `/www/`)

### Configuration
- **config.ini**: FluffOS runtime configuration
- **Master file**: `/adm/kernel/master.c`
- **Simul efuns**: `/adm/kernel/simul_efun.c`

### Admin Account
First registered user with ID `admin` receives full administrator privileges.

### Backup System
Daily backups stored in `/backup/` with date-stamped directories (format: `YYYY-M-D`).

## Common Patterns

### Room Definition
```lpc
inherit ROOM;
void create() {
    set("short", "房間短描述");
    set("long", @LONG
這裡是較長的房間描述。
LONG );
    set("exits", ([
        "north" : "/d/city/street1",
        "south" : "/d/city/street2",
    ]));
    set("objects", ([
        "/clone/npc/guard" : 2,  // Spawn 2 guards
    ]));
    setup();
    replace_program(ROOM);
}
```

### NPC Definition
```lpc
inherit NPC;
void create() {
    set_name("守衛", ({ "shou wei", "guard" }));
    set("long", "一名盡職的守衛。\n");
    set("age", 25);
    set("str", 25);
    set("combat_exp", 10000);
    setup();
}
```

### Command Implementation
Place in `/cmds/usr/` (regular) or `/cmds/wiz/` (wizard-only):
```lpc
inherit F_CLEAN_UP;
int main(object me, string arg) {
    // Command logic
    return 1;  // Success
}
```

## Key Systems

- **Combat**: Managed by `COMBAT_D` (`/adm/daemons/combatd.c`), uses `/kungfu/skill/` skill files
- **Skills**: `SKILLS_D` handles learning, practice, improve system
- **Quests**: `/quest/` directory, tracked by `QUEST_D`
- **Channels**: Communication via `CHANNEL_D` (chat, rumor, sys)
- **Virtual Objects**: Template-based generation via `TEMPLATE_D` and `VIRTUAL_D`
- **Instanced Dungeons**: Copy-on-demand zones via `FUBEN_D` (副本系統)

## Combat System Architecture

### Combat Daemon (`/adm/daemons/combatd.c`)
Central combat engine managing all combat calculations and mechanics (4720+ lines):

**Core Combat Values:**
- `ATTACK` (0): Attack effectiveness calculation
- `DODGE` (1): Evasion ability
- `PARRY` (2): Blocking/parrying capability
- `DAMAGE` (3): Damage calculation
- `FORCE2` (4): Internal force (內力) related combat

**Body Parts System:**
Limbs have different damage modifiers (`limb_damage` mapping):
- Critical areas (danger_limbs): 頭部 (100), 頸部 (90), 胸口 (90), 後心 (80), 小腹 (70)
- Non-critical: 左手 (20), 右手 (30), 尾巴 (10)

**Armor Protection:**
`armor_vs_limb` mapping links body parts to armor types:
```lpc
"胸口" : ({ TYPE_CLOTH, TYPE_ARMOR, TYPE_SURCOAT })
"左手" : ({ TYPE_WRISTS })
"左腳" : ({ TYPE_BOOTS })
```

**Special Combat Mechanics:**
- Counter attacks (反擊): `counter_msg` array
- Critical hits (暴擊): `critical_msg` array with visual effects
- Special parries: Star Move (斗轉星移), Qiankun Move (乾坤大挪移)
- Throwing weapon parries (暗器格擋)
- Six Meridian Sword (六脈神劍) special handling

### Skill System (`/kungfu/skill/`)

**Skill File Structure:**
Each skill is a `.c` file inheriting `SKILL`:
```lpc
inherit SKILL;
mapping *action = ({
    ([
        "action": "Attack description with $N/$n placeholders",
        "attack": 70,    // Attack bonus
        "dodge": 60,     // Dodge bonus
        "parry": 70,     // Parry bonus
        "damage": 120,   // Damage multiplier
        "lvl": 0,        // Minimum level for this move
        "damage_type": "刺傷"  // Damage type
    ]),
    // More action mappings...
});
```

**Perform Actions (絕招/Special Moves):**
Located in `/kungfu/skill/<skill_id>/<perform_name>.c`:
- Each perform file has `int perform(object me, object target)` function
- Skills define `string perform_action_file(string action)` to link performs
- Checks: skill level, weapon type, combat state, busy state
- Example structure:
```lpc
int perform(object me, object target) {
    // Permission checks
    if (userp(me) && !query("can_perform/skill/move", me) < 100)
        return notify_fail("你還沒有受過高人指點...\n");

    // Skill/weapon/state validations
    // AP (attack power) vs DP (defense power) calculations
    // Execute attack sequence with COMBAT_D->do_attack()
    // Apply effects, busy states, damage
}
```

**Skill Categories:**
Major skill types organized in `/kungfu/skill/`:
- Weapons: `sword.c`, `blade.c`, `staff.c`, `whip.c`, `throwing.c`
- Unarmed: `cuff.c`, `strike.c`, `finger.c`, `claw.c`, `leg.c`
- Internal: `force.c`, various `*-xinfa.c`, `*-shengong.c`
- Special: `dodge.c`, `parry.c`, specific martial arts schools

**Attack/Defense Calculation Pattern:**
```lpc
ap = skill * 3/2 + query("level", me) * 20 +
     me->query_skill("martial-cognize", 1);
dp = target->query_skill(type, 1) * 2 +
     query("level", target) * 20;
```

### Combat Flow
1. Attacker calls `COMBAT_D->do_attack(me, target, weapon, type)`
2. Calculate AP (attack power) and DP (defense power)
3. Determine hit/miss/parry/dodge outcome
4. Calculate damage based on weapon, skill, and armor
5. Apply damage to specific body part
6. Check for special effects (counter, critical, special parries)
7. Handle victory/defeat conditions

## Security
- Use `seteuid(getuid())` or `seteuid(ROOT_UID)` appropriately
- Check permissions with `SECURITY_D->valid_grant()`
- Validate user input in all commands to prevent exploits

## References
- FluffOS docs: https://www.fluffos.info/
- Original codebase: Lonely's NT MudLIB
- Driver version: FluffOS v2025.1205.0
