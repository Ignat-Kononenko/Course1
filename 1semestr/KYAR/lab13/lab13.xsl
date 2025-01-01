<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<body>        
    <title>Pens</title>
    <h2>Pens</h2>
    <table border="1">
        <tr bgcolor="#9acd32">
            <th>PEN</th>
            <th>PRICE</th>
         </tr>
                <xsl:for-each select="PENS/NAME">
<xsl:sort select="PRICE" data-type="number"/>
<tr>
<td><xsl:value-of select="PEN"/></td>
<td><xsl:value-of select="PRICE"/></td>
</tr>
</xsl:for-each>
</table>
</body> 
</html>
</xsl:template>
</xsl:stylesheet>