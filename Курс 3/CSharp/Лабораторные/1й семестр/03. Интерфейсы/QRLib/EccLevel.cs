/// <summary> 
/// Error Correction Level 
/// </summary> 
public enum EccLevel : byte 
{ 
    /// <summary> 
    /// 7 % Low 11 
    /// </summary> 
    L  = 0,  
    /// <summary> 
    /// 15 % Medium 10 
 	/// </summary> 
    M = 1, 
    /// <summary> 
    /// 25 % Quartile 01 
    /// </summary> 
    Q = 2, 
    /// <summary> 
    /// 30 % High 00 
    /// </summary> 
    H = 3 
} 
