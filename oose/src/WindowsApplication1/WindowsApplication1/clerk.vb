Public Class clerk

    Dim dbConn As New ADODB.Connection
    Dim recSet As New ADODB.Recordset
    Dim flag As Boolean

    Private Sub AddNewEntryToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AddNewEntryToolStripMenuItem.Click
        new_entry.Show()
        Me.Hide()
    End Sub

    Private Sub LogoutToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LogoutToolStripMenuItem.Click
        Me.Close()
        login.Show()
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        flag = False

        If Not TextBox1.Text = "" Then
            Label2.Text = ""

            Dim sqlStr As String

            'check whether entry exists        
            sqlStr = "SELECT id FROM p_details WHERE id=" & TextBox1.Text
            recSet.Open(sqlStr, dbConn)

            If recSet.EOF Then
                Label2.Text = "Entry not found"
                Label7.Text = "<first> <middle> <last>"
                Label11.Text = "<day> <month> <year>"
                Label15.Text = "<gender>"
                Label9.Text = "<dept. name>"
                Label10.Text = "<permanent address>"
                Label12.Text = "<landline number>"
                Label14.Text = "<mobile number>"

            ElseIf Trim(recSet.Fields(0).Value) = TextBox1.Text Then
                flag = True
                sqlStr = "SELECT * FROM p_details WHERE id=" & TextBox1.Text
                recSet.Close()
                recSet.Open(sqlStr, dbConn)

                Label7.Text = Trim(recSet.Fields(1).Value) 'name
                Label11.Text = (recSet.Fields(2).Value) 'dob

                'gender
                If (recSet.Fields(4).Value) = 1 Then
                    Label15.Text = "Male"
                ElseIf (recSet.Fields(4).Value) = 2 Then
                    Label15.Text = "Female"
                End If
                Label9.Text = Trim(recSet.Fields(3).Value) 'dept

                'concat address
                Label10.Text = Trim(recSet.Fields(5).Value) & ", " & Trim(recSet.Fields(6).Value) & vbCrLf & Trim(recSet.Fields(7).Value) & ", " & Trim(recSet.Fields(8).Value) & vbCrLf & (recSet.Fields(9).Value)

                'landline and mobile nos
                Label12.Text = (recSet.Fields(10).Value)
                Label14.Text = (recSet.Fields(11).Value)
            End If
            recSet.Close()

        End If
    End Sub

    Private Sub clerk_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        dbConn.ConnectionString = "Driver={Microsoft ODBC for Oracle};" & "UID=System;PWD=sys"
        dbConn.Open()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Try

            Label2.Text = ""

            If Not TextBox1.Text = "" And flag = True Then
                Dim sqlStr As String
                Dim tmpStr As String
                Dim recordCount As Integer
                Dim objRS As New ADODB.Recordset

                tmpStr = "SELECT count(*) FROM p_queue"
                With objRS
                    .CursorLocation = ADODB.CursorLocationEnum.adUseServer
                    .CursorType = ADODB.CursorTypeEnum.adOpenForwardOnly
                    .LockType = ADODB.LockTypeEnum.adLockReadOnly
                End With
                objRS.Open(tmpStr, dbConn)
                recordCount = objRS.Fields(0).Value
                objRS.Close()

                'check if entry already exists in the queue
                sqlStr = "SELECT id FROM p_queue WHERE id=" & TextBox1.Text
                recSet.Open(sqlStr, dbConn)

                If recSet.EOF = True Then
                    recSet.Close()
                    sqlStr = "INSERT INTO p_queue VALUES (" & (recordCount + 1) & "," & TextBox1.Text & ")"
                    recSet.Open(sqlStr, dbConn)
                    Label2.Text = "Entry queued"
                Else
                    Label2.Text = "Entry already exists in the queue"
                End If

                recSet.Close()
            Else
                Label2.Text = "Unable to add to the queue"
            End If


        Catch ex As Exception

        End Try
    End Sub

    Private Sub Button4_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
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

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Try
            Dim recordCount As Integer
            Dim objRS As New ADODB.Recordset
            With objRS
                .CursorLocation = ADODB.CursorLocationEnum.adUseServer
                .CursorType = ADODB.CursorTypeEnum.adOpenForwardOnly
                .LockType = ADODB.LockTypeEnum.adLockReadOnly
            End With
            objRS.Open("SELECT count(*) FROM p_queue", dbConn)
            If objRS.EOF = False Then
                recordCount = objRS.Fields(0).Value
            End If

            objRS.Close()


            If recordCount > 0 And Not ListBox1.SelectedIndex < 0 And Not ListBox1.SelectedItem = "<no entries>" Then

                recSet.Open("DELETE FROM p_queue WHERE place=" & (ListBox1.SelectedIndex + 1), dbConn)

                Dim x As Integer
                x = ListBox1.SelectedIndex + 1
                Dim sqlStr As String

                While x < recordCount + 1
                    sqlStr = "UPDATE p_queue SET place=" & x & "WHERE place=" & (x + 1)
                    recSet.Open(sqlStr, dbConn)

                    x = x + 1
                End While

                ListBox1.Items.RemoveAt(ListBox1.SelectedIndex)
            End If

        Catch ex As Exception

        End Try
    End Sub

End Class