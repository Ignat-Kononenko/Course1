<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<body>        
    <title>Pens</title>
    <h2>Pens</h2>
    <table border="1">
        <tr bgcolor="#9acd32">
            <th>name</th>
            <th>grade</th>
         </tr>
                <xsl:for-each select="school/NAME">
<tr>
<td><xsl:value-of select="name"/></td>
<xsl:choose>
<xsl:when test="grade &gt; 8">
<td bgcolor="#ff00ff">
<xsl:value-of select="grade"/></td>
</xsl:when>
<xsl:when test="grade &lt; 4">
<td bgcolor="yellow">
<xsl:value-of select="grade"/></td>
</xsl:when>
 <xsl:otherwise>
 <td><xsl:value-of select="grade"/></td>
</xsl:otherwise>
</xsl:choose>
 </tr>
</xsl:for-each>
</table>
</body> 
</html>
</xsl:template>
</xsl:stylesheet>