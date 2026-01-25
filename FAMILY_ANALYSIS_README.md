# NT7 MUD Family Power Curve Analysis - README

## 概述 (Overview)

本專案分析了NT7泥潭MUD遊戲中21個武林門派的戰力曲線，基於 [combatd.c](./adm/daemons/combatd.c) 中的戰鬥計算公式。

This project analyzes the power curves of 21 martial arts families in NT7 MUD based on the combat formulas in combatd.c.

## 生成的文件 (Generated Files)

### 圖表 (Graphs)
1. **family_power_comparison_master.png** - 所有門派在宗師級經驗的綜合戰力對比
2. **family_power_details_top9.png** - 前9大門派的攻擊力、閃避、傷害細項分析
3. **family_power_by_exp_level.png** - 5個代表門派在不同經驗等級的成長曲線
4. **top5_families_comparison.png** - 戰力前五強門派的直接對比

### 數據 (Data)
- **family_power_data.json** - 完整的戰力數據，可用於進一步分析

## 戰力計算公式 (Combat Formulas)

基於 [combatd.c](./adm/daemons/combatd.c) 的關鍵函數：

### 1. 基礎戰力 (Base Power) - `skill_power()`
```
power = (skill_level / 10)² * skill_level / 10000
power = power / 30 * attribute  // str for attack, dex for defense
power = power / 2 + valid_power(combat_exp) / 2
power += power * famsk_buff / 100  // Family skill bonus
power += power * yuanshen_level / 100  // Yuanshen bonus
```

### 2. 攻擊力 (Attack Power) - `attack_value()`
```
AP = skill_power(skill, combat_exp, strength, "attack")
AP += AP / 300 * ability_buff("str")
AP += skill_level * buff
```

### 3. 防禦力 (Defense Power) - `defend_value()`
```
DP = skill_power(skill, combat_exp, dexterity, "defense")
DP += DP / 300 * ability_buff("dex")
DP += skill_level * buff
```

### 4. 傷害計算 (Damage) - `attack_damage()`
```
damage = skill_level + jiali + damage/10 * strength
damage += action["damage"] * damage / 100
damage += damage * yuanshen_level / 100
```

### 5. 門派特技加成 (Family Skill Buff) - `famsk_buff()`

各門派擁有獨特的特技加成系統：

- **逍遙派**: 逍遙遊 (xiaoyao-you) - 每100級+1%
- **武當派**: 天威正氣 (tianwei-zhengqi) - 每50級+1%
- **華山派/劍宗**: 劍意 (jianyi) - 每50級+1%
- **血刀門**: 血影大法 (xueying-dafa) - 每50級+1%
- **桃花島**: 奇門玄術 (qimen-xuanshu) - 每50級+1%
- **峨嵋派**: 靜心 (jingxin) - 每50級+1%

## 門派戰力排名 (Family Power Rankings)

### 技能500級 @ 宗師級經驗 (10,000,000,000 exp)

| 排名 | 門派 | 戰力值 | 特色 |
|------|------|--------|------|
| 1 | 逍遙派 | 45,702 | 逍遙遊加成最高 |
| 2-7 | 武當/華山/峨嵋/桃花島/血刀/劍宗 | 45,326 | 擁有50級/1%特技加成 |
| 8-21 | 其他門派 | 43,574 | 無特殊加成或加成較低 |

## 關鍵發現 (Key Findings)

1. **逍遙派優勢**: 由於「逍遙遊」的獨特加成機制（100級+1%），逍遙派在高技能等級時略勝一籌

2. **特技加成重要性**: 擁有特技加成的門派（武當、華山、峨嵋等）比無特技加成的門派戰力高約4%

3. **成長曲線**: 
   - 技能0-200級：成長較慢
   - 技能200-400級：快速成長期
   - 技能400-500級：進入平台期

4. **經驗影響**: 
   - 經驗值對戰力的影響在10億以下非常顯著
   - 超過100億後，經驗對戰力的邊際效益遞減

5. **門派平衡性**: 整體而言，各門派戰力差距不大（最高與最低相差約5%），遊戲平衡性良好

## 使用方法 (Usage)

### 運行分析腳本
```bash
python family_power_analysis.py
```

### 自定義參數
修改腳本中的參數來測試不同情境：
- `skill_levels`: 技能等級範圍
- `exp_levels`: 經驗等級
- `strength/dexterity`: 屬性值
- `reborn_times`: 轉生次數
- `yuanshen_level`: 元神等級

### 查看數據
```python
import json
with open('family_power_data.json', 'r', encoding='utf-8') as f:
    data = json.load(f)
    # 分析特定門派
    xiaoyao_data = data['families']['xiaoyao']
```

## 技術細節 (Technical Details)

### 戰力指標 (Power Metrics)
腳本計算以下四個核心指標：

1. **攻擊力 (Attack Power)**: 命中率和攻擊成功率
2. **閃避力 (Dodge Power)**: 躲避攻擊的能力
3. **招架力 (Parry Power)**: 格擋攻擊的能力
4. **傷害值 (Damage)**: 攻擊造成的實際傷害

**綜合戰力 (Power Score)** 計算公式：
```
Power Score = AP × 0.35 + Dodge × 0.25 + Parry × 0.25 + Damage × 0.15
```

### 數據來源 (Data Sources)

1. **門派數據**: [/adm/daemons/familyd.c](./adm/daemons/familyd.c)
   - 門派名稱、ID映射
   - 門派聲望值

2. **戰鬥公式**: [/adm/daemons/combatd.c](./adm/daemons/combatd.c)
   - `skill_power()` (line 679-738)
   - `attack_value()` (line 2148-2180)
   - `defend_value()` (line 2186-2216)
   - `attack_damage()` (line 895-948)
   - `famsk_buff()` (line 566-677)

3. **技能系統**: [/kungfu/skill/](./kungfu/skill/)
   - 各門派的武功技能

## 圖表說明 (Chart Descriptions)

### 1. family_power_comparison_master.png
展示所有21個門派在宗師級經驗下的綜合戰力曲線，清楚顯示逍遙派的優勢。

### 2. family_power_details_top9.png
9宮格展示前9大門派的細項分析：
- 紅線：攻擊力 (AP)
- 藍線：閃避力 (DP)
- 綠線：傷害值 (Damage)

### 3. family_power_by_exp_level.png
展示5個代表門派在6個不同經驗等級的成長曲線，說明經驗值的重要性。

### 4. top5_families_comparison.png
前5強門派的直接對比，更清晰地展示頂尖門派之間的差異。

## 未來改進 (Future Improvements)

1. **連招系統**: 加入perform技能的分析
2. **裝備影響**: 考慮武器、防具的加成
3. **實戰模擬**: 模擬不同門派之間的PK勝率
4. **陣法加成**: 加入陣法對戰力的影響
5. **轉生元神**: 更詳細的轉生和元神系統分析

## 參考資料 (References)

- NT7 MUD 官方文檔: `/help/family`
- 戰鬥系統文檔: `/help/combat`
- 技能系統: `/help/skills`
- LPC 語言參考: FluffOS Documentation

## 作者 (Author)

基於 NT7 MUD 源代碼分析生成

## 授權 (License)

本分析工具僅供學習和研究使用
