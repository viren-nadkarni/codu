Public Class pharma

    Dim dbConn As New ADODB.Connection

    Private Sub LogoutToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LogoutToolStripMenuItem.Click
        Me.Close()
        login.Show()
    End Sub

    Private Sub pharma_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        dbConn.ConnectionString = "Driver={Microsoft ODBC for Oracle};" & "UID=System;PWD=sys"
        dbConn.Open()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Try
            Dim recordCount As Integer
            Dim objRS As New ADODB.Recordset
            With objRS
                .CursorLocation = ADODB.CursorLocationEnum.adUseServer
                .CursorType = ADODB.CursorTypeEnum.adOpenForwardOnly
                .LockType = ADODB.LockTypeEnum.adLockReadOnly
            End With
            objRS.Open("SELECT count(*) FROM p_queue", dbConn)
            recordCount = objRS.Fields(0).Value
            objRS.Close()


            Dim sqlStr2 As String
            Dim recSet As New ADODB.Recordset
            Dim recSet2 As New ADODB.Recordset
            Dim counter As Integer
            counter = 0

            recSet.Open("SELECT id FROM p_queue", dbConn)

            If recSet.EOF = False Then
                ListBox1.Items.Clear()

                Do While recSet.EOF = False And counter < recordCount

                    sqlStr2 = "SELECT name FROM p_details WHERE id=" & (recSet.Fields(0).Value)
                    recSet.MoveNext()

                    recSet2.Open(sqlStr2, dbConn)

                    ListBox1.Items.Add(Trim(recSet2.Fields(0).Value))

                    counter = counter + 1

                    recSet2.Close()
                Loop

            End If
            recSet.Close()

        Catch ex As Exception

        End Try
    End Sub

    Private Sub ListBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ListBox1.SelectedIndexChanged
        Try
            Dim recSet As New ADODB.Recordset
            Label1.Text = ""
            Label12.Text = ""
            Label13.Text = ""

            If Not ListBox1.SelectedItem = "" And Not ListBox1.SelectedItem = "<no entries>" Then
                recSet.Open(("SELECT * FROM p_details WHERE name='" & ListBox1.SelectedItem & "'"), dbConn)
                Label6.Text = recSet.Fields(0).Value
                Label7.Text = recSet.Fields(1).Value
                Label11.Text = recSet.Fields(2).Value
                Label9.Text = recSet.Fields(3).Value

                recSet.Close()
                recSet.Open("SELECT * FROM p_health WHERE id=" & Label6.Text, dbConn)

                While (recSet.EOF = False)
                    Label12.Text = recSet.Fields(1).Value
                    Label13.Text = recSet.Fields(4).Value
                    recSet.MoveNext()

                End While
            Else
                Label1.Text = "Invalid entry selected"
            End If

        Catch ex As Exception

        End Try
    End Sub

End Class